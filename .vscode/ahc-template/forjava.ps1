# compile all Java sources into Java 8 bytecode (class version 52.0)
# https://atcoder.jp/contests/rco-contest-2019-qual/tasks/rco_contest_2019_qual_a
# スコアの出力形式
# score_regex = '(?m)^\s*score\s*:\s*(?P<score>\d+)\s*$'
#
# Run the visualizer to calculate the score
#[[test.test_steps]]
#program = "java"
#args = [
#    "Judge", 
#    "./in/{SEED04}.txt",
#    "./out/{SEED04}.txt",
#]
Set-Location .\2025\6\rco_contest_2019_qual_a\tools
chcp 65001
javac -encoding UTF-8 Generator.java --release 8
javac -encoding UTF-8 Judge.java --release 8
# generate test case with seed $i (four digits like 0000, 0001, ..., 0099)
for ($i = 0; $i -lt 100; $i++) {
  $i_ = "{0:D4}" -f $i
  Write-Host "Generating test case with seed $i"
  $input = java Generator -Dfile.encoding=UTF-8 -seed $i_ # > in/$i_.txt
  # change encoding to UTF-8 (no BOM)
  # write UTF-8 without BOM via .NET API, preserving newlines
  [System.IO.File]::WriteAllLines(
    "D:\atcoder\2025\6\rco_contest_2019_qual_a\tools\in\$i_.txt",
    $input,
    (New-Object System.Text.UTF8Encoding($false))
  )
}