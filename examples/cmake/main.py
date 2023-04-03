import sys

if len(sys.argv) < 2:
    print("Provide path to `cmake_example` Python module. Should be `<build_dir>/examples/cmake`.")
    exit(1)
else:
    sys.path.append(sys.argv[1])

import cmake_example

print(f'5 + 7 equals: {cmake_example.add(5,7)}')
