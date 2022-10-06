# CMake generated Testfile for 
# Source directory: D:/login bot/googletest-template/test
# Build directory: D:/login bot/googletest-template/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(AllTests "D:/login bot/googletest-template/test/Debug/runAllTests.exe")
  set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "D:/login bot/googletest-template/test/CMakeLists.txt;15;add_test;D:/login bot/googletest-template/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(AllTests "D:/login bot/googletest-template/test/Release/runAllTests.exe")
  set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "D:/login bot/googletest-template/test/CMakeLists.txt;15;add_test;D:/login bot/googletest-template/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(AllTests "D:/login bot/googletest-template/test/MinSizeRel/runAllTests.exe")
  set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "D:/login bot/googletest-template/test/CMakeLists.txt;15;add_test;D:/login bot/googletest-template/test/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(AllTests "D:/login bot/googletest-template/test/RelWithDebInfo/runAllTests.exe")
  set_tests_properties(AllTests PROPERTIES  _BACKTRACE_TRIPLES "D:/login bot/googletest-template/test/CMakeLists.txt;15;add_test;D:/login bot/googletest-template/test/CMakeLists.txt;0;")
else()
  add_test(AllTests NOT_AVAILABLE)
endif()
subdirs("gtest")
