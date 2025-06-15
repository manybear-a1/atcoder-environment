# compile all Java sources into Java 8 bytecode (class version 52.0)
# change location
Set-Location .\2025\6\rco_contest_2019_qual_a\tools
javac --release 8 *.java
# generate test case with seed $i (four digits like 0000, 0001, ..., 0099)
for ($i = 0; $i -lt 100; $i++) {
  $i_ = "{0:D4}" -f $i
  Write-Host "Generating test case with seed $i"
  java Generator -seed $i_ > in/$i_.txt
}
