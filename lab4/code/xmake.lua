add_rules("mode.debug", "mode.release")

target("lab4_scheduler")
    set_kind("binary")
    set_languages("cxx20")
    add_files("scheduler/*.cpp")

target("lab4_datagen")
    set_kind("binary")
    set_languages("cxx20")
    add_files("datagen/*.cpp")
