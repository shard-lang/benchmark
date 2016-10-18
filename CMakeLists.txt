# ************************************************************************* #
# This file is part of Shard.                                               #
#                                                                           #
# Shard is free software: you can redistribute it and/or modify             #
# it under the terms of the GNU Affero General Public License as            #
# published by the Free Software Foundation.                                #
#                                                                           #
# This program is distributed in the hope that it will be useful,           #
# but WITHOUT ANY WARRANTY; without even the implied warranty of            #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the              #
# GNU Affero General Public License for more details.                       #
#                                                                           #
# You should have received a copy of the GNU Affero General Public License  #
# along with this program. If not, see <http://www.gnu.org/licenses/>.      #
# ************************************************************************* #

cmake_minimum_required(VERSION 3.1)

# ************************************************************************* #

# Init google benchmark submodule
if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vendor/benchmark/CMakeLists.txt")
    find_package(Git REQUIRED)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive vendor/benchmark
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif ()

# Init shard library
# It's not a submodule because different branch can be used to test difference
# and locking to some commit can cause issues
if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vendor/shard/CMakeLists.txt")
    find_package(Git REQUIRED)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone https://github.com/shard-lang/shard vendor/shard
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif ()

# ************************************************************************* #

message("You can test different version of shard library. Just checkout desired commit in vendor/shard and then rebuild")

# ************************************************************************* #

# Google benchmark
add_subdirectory(vendor/benchmark)

# Shard library
add_subdirectory(vendor/shard)

# ************************************************************************* #

# C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED On)
set(CMAKE_CXX_EXTENSIONS Off)

# ************************************************************************* #

# Tokenizer benchmark
add_executable(tokenizer src/Tokenizer.cpp)
target_link_libraries(tokenizer benchmark shard-tokenizer)

# ************************************************************************* #