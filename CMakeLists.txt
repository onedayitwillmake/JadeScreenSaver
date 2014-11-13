cmake_minimum_required(VERSION 2.8.4)
project(CircleMandala)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    blocks/Cairo/include/cinder/cairo/Cairo.h
    blocks/Cairo/include/macosx/cairo-deprecated.h
    blocks/Cairo/include/macosx/cairo-features.h
    blocks/Cairo/include/macosx/cairo-pdf.h
    blocks/Cairo/include/macosx/cairo-ps.h
    blocks/Cairo/include/macosx/cairo-quartz.h
    blocks/Cairo/include/macosx/cairo-svg.h
    blocks/Cairo/include/macosx/cairo-version.h
    blocks/Cairo/include/macosx/cairo.h
    blocks/Cairo/lib/macosx/libcairo.a
    blocks/Cairo/lib/macosx/libpixman-1.a
    blocks/Cairo/lib/macosx/libpng14.a
    blocks/Cairo/src/Cairo.cpp
    include/Resources.h
    resources/CinderApp.icns
    source/Search/Strategies/DepthFirstSearch.cpp
    source/Search/Strategies/DepthFirstSearch.h
    source/Search/Strategies/GraphSearch.cpp
    source/Search/Strategies/GraphSearch.h
    source/Search/Action.cpp
    source/Search/Action.h
    source/Search/Agent.cpp
    source/Search/Agent.h
    source/Search/Comparators.h
    source/Search/Goal.cpp
    source/Search/Goal.h
    source/Search/Result.cpp
    source/Search/Result.h
    source/Search/Sequence.cpp
    source/Search/Sequence.h
    source/Search/State.cpp
    source/Search/State.h
    source/Constants.cpp
    source/Constants.h
    source/Flower.cpp
    source/Flower.h
    source/Grid.cpp
    source/Grid.h
    source/GridDirections.h
    source/GridPoint.cpp
    source/GridPoint.h
    source/JadeFlower.cpp
    source/Petal.cpp
    source/Petal.h)

#incude cinder and boost header files and libraries.
set(CINDER_ROOT "../../GIT/LIBRARY/cinder_0.8.6_mac")
include_directories("${CINDER_ROOT}/include" "${CINDER_ROOT}/boost" "${CINDER_ROOT}/blocks/Cairo/include")
link_directories("${CINDER_ROOT}/lib" "${CINDER_ROOT}/macosx")

add_executable(CircleMandala ${SOURCE_FILES})