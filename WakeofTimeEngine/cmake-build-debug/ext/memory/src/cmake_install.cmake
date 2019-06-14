# Install script for directory: /home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/ext/memory/src/libfoonathan_memory-0.6.1-dbg.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/foonathan_memory" TYPE FILE FILES "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/ext/memory/src/config_impl.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/foonathan_memory/foonathan/memory/detail" TYPE FILE FILES "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/ext/memory/src/container_node_sizes_impl.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/foonathan_memory/foonathan/memory" TYPE FILE FILES
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/aligned_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/allocator_storage.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/allocator_traits.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/config.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/container.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/debugging.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/default_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/deleter.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/error.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/fallback_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/malloc_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/heap_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/iteration_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/joint_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/memory_arena.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/memory_pool.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/memory_pool_collection.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/memory_pool_type.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/memory_resource_adapter.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/memory_stack.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/namespace_alias.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/new_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/segregator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/smart_ptr.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/static_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/std_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/temporary_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/threading.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/tracking.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/virtual_memory.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/ext/memory/src/container_node_sizes_impl.hpp"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/foonathan_memory/foonathan/memory/detail" TYPE FILE FILES
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/align.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/assert.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/container_node_sizes.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/debug_helpers.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/ebo_storage.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/free_list.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/free_list_array.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/lowlevel_allocator.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/memory_stack.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/small_free_list.hpp"
    "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/ext/memory/include/foonathan/memory/detail/utility.hpp"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/foonathan_memory/cmake" TYPE FILE FILES "/home/alexander/Desktop/WakeofTime/WakeofTimeEngine/cmake-build-debug/ext/memory/src/cmake/foonathan_memory-version.cmake")
endif()

