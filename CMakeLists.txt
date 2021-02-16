cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME 00demo)

project(${PROJECT_NAME} VERSION 0.1.0) 


include(CTest)
enable_testing()

# set(DIR_SRC 
#     "00_demo/add.cpp"
#     "00_demo/main_demo.cpp"
# )
aux_source_directory("00_demo/" DIR_SRC) #这两种方式都行

add_executable(${PROJECT_NAME} ${DIR_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
