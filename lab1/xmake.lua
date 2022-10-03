-- This file is only used for building.

target("ma")
    set_kind("binary")
    add_files("./code/*.cpp|datagen.cpp")
    add_headerfiles("./code/*.hpp")

target("datagen")
    set_kind("binary")
    add_files("./code/datagen.cpp")
