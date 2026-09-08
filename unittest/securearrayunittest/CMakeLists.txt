ENABLE_TESTING()

set(securearrayunittest_bin_SRCS securearrayunittest.cpp)  

add_executable( securearrayunittest ${securearrayunittest_bin_SRCS} )

target_link_qca_test_libraries(securearrayunittest)
target_include_directories(securearrayunittest PRIVATE ${CMAKE_SOURCE_DIR}/src/support)

add_qca_test(securearrayunittest "SecureArray")
