project('meson-cpp-pybind11', 'cpp', version : '1.0.0')

# python module
python_installation = import('python').find_installation('python3')
pybind11_includes = run_command(python_installation, '-c', 'import pybind11; print(pybind11.get_include());', check : true).stdout().strip()

# api
api_lib = static_library('api',
    ['api/api.h', 'api/api.cpp']
)

python_installation.extension_module('api', 
    sources : ['api/api-python.cpp'],
    include_directories : pybind11_includes,
    dependencies : python_installation.dependency(),
    link_with : api_lib,
)

executable('cpp-client',
    sources : ['main.cpp'],
    include_directories : ['api'],
    link_with : api_lib,
)

# examples
python_installation.extension_module('meson_example', 
    sources : ['examples/meson/main.cpp'],
    include_directories : pybind11_includes,
    dependencies : python_installation.dependency(),
)
