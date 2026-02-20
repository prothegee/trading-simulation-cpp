#!/usr/bin/sh
set -e;

clang-format --version;

# find . -name *.hh -o -name *.cc -exec dos2unix {} \;
find . -name *.hh -o -name *.cc|xargs clang-format -i -style=file;

echo "format finished.";
