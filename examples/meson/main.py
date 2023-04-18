import sys

if len(sys.argv) < 2:
    print("Provide path to `meson_example` Python module. Should be `<build_dir>/examples/meson`.")
    exit(1)
else:
    sys.path.append(sys.argv[1])

import meson_example

print(f'5 + 7 equals: {meson_example.add(5,7)}')
