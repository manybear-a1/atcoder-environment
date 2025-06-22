import re
import sys
import os
from typing import Set
#from https://github.com/ymatsux/competitive-programming/blob/main/combiner/hoge.cpp

def read_file_content(file_name: str) -> str:
    with open(file_name, "r") as f:
        return f.read()


def make_converted_file_content(
        file_name: str,
        stack: list[str],
        added_file_names: Set[str]) -> str:
    file_path = os.path.normpath(file_name)
    content = read_file_content(file_path)
    content_lines = content.split("\n")
    for i in range(len(content_lines)):
        line = content_lines[i]
        match = re.match(r"^\s*#include\s+\"(.*)\"\s*$", line)
        if match:
            include_rel = match.group(1)
            include_path = os.path.normpath(os.path.join(os.path.dirname(file_path), include_rel))
            if include_path not in added_file_names:
                if include_path in stack:
                    print("Circular dependency detected: "
                          f"{' > '.join(stack + [include_path])}")
                    exit(1)
                stack.append(include_path)
                content_lines[i] = make_converted_file_content(include_path, stack, added_file_names)
                added_file_names.add(include_path)
                stack.pop()
            else:
                content_lines[i] = ""
    return "\n".join(content_lines)


def main(argv: list[str]):
    if len(argv) != 3:
        print("Usage: python3 combiner.py <source_file> <output_file>")
        sys.exit(1)
    converted_main_file_content = make_converted_file_content(
        argv[1], [argv[1]], set())
    with open(argv[2], "w") as f:
        f.write(converted_main_file_content)


if __name__ == "__main__":
    main(sys.argv)
