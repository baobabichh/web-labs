# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/goshan9/web-labs/web-labs/image_service

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/goshan9/web-labs/web-labs/image_service

# Include any dependencies generated for this target.
include CMakeFiles/image_client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/image_client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image_client.dir/flags.make

CMakeFiles/image_client.dir/image_client.cc.o: CMakeFiles/image_client.dir/flags.make
CMakeFiles/image_client.dir/image_client.cc.o: image_client.cc
CMakeFiles/image_client.dir/image_client.cc.o: CMakeFiles/image_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/goshan9/web-labs/web-labs/image_service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image_client.dir/image_client.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image_client.dir/image_client.cc.o -MF CMakeFiles/image_client.dir/image_client.cc.o.d -o CMakeFiles/image_client.dir/image_client.cc.o -c /home/goshan9/web-labs/web-labs/image_service/image_client.cc

CMakeFiles/image_client.dir/image_client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image_client.dir/image_client.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goshan9/web-labs/web-labs/image_service/image_client.cc > CMakeFiles/image_client.dir/image_client.cc.i

CMakeFiles/image_client.dir/image_client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image_client.dir/image_client.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goshan9/web-labs/web-labs/image_service/image_client.cc -o CMakeFiles/image_client.dir/image_client.cc.s

# Object files for target image_client
image_client_OBJECTS = \
"CMakeFiles/image_client.dir/image_client.cc.o"

# External object files for target image_client
image_client_EXTERNAL_OBJECTS =

image_client: CMakeFiles/image_client.dir/image_client.cc.o
image_client: CMakeFiles/image_client.dir/build.make
image_client: librg_grpc_proto.a
image_client: libmy_grpc_lib.a
image_client: /usr/local/lib/libabsl_flags_parse.a
image_client: /usr/local/lib/libabsl_log_initialize.a
image_client: /usr/local/lib/libabsl_log_globals.a
image_client: /usr/local/lib/libgrpc++_reflection.a
image_client: /usr/local/lib/libgrpc++.a
image_client: /usr/local/lib/libprotobuf.a
image_client: /usr/local/lib/libgrpc.a
image_client: /usr/local/lib/libupb_json_lib.a
image_client: /usr/local/lib/libupb_textformat_lib.a
image_client: /usr/local/lib/libupb_mini_descriptor_lib.a
image_client: /usr/local/lib/libupb_wire_lib.a
image_client: /usr/local/lib/libutf8_range_lib.a
image_client: /usr/local/lib/libupb_message_lib.a
image_client: /usr/local/lib/libupb_base_lib.a
image_client: /usr/local/lib/libupb_mem_lib.a
image_client: /usr/local/lib/libre2.a
image_client: /usr/local/lib/libz.a
image_client: /usr/local/lib/libcares.a
image_client: /usr/local/lib/libgpr.a
image_client: /usr/local/lib/libssl.a
image_client: /usr/local/lib/libcrypto.a
image_client: /usr/local/lib/libaddress_sorting.a
image_client: /usr/local/lib/libabsl_log_initialize.a
image_client: /usr/local/lib/libabsl_log_internal_check_op.a
image_client: /usr/local/lib/libabsl_leak_check.a
image_client: /usr/local/lib/libabsl_die_if_null.a
image_client: /usr/local/lib/libabsl_log_internal_conditions.a
image_client: /usr/local/lib/libabsl_log_internal_message.a
image_client: /usr/local/lib/libabsl_examine_stack.a
image_client: /usr/local/lib/libabsl_log_internal_format.a
image_client: /usr/local/lib/libabsl_log_internal_proto.a
image_client: /usr/local/lib/libabsl_log_internal_nullguard.a
image_client: /usr/local/lib/libabsl_log_internal_log_sink_set.a
image_client: /usr/local/lib/libabsl_log_globals.a
image_client: /usr/local/lib/libabsl_log_internal_globals.a
image_client: /usr/local/lib/libabsl_log_sink.a
image_client: /usr/local/lib/libabsl_log_entry.a
image_client: /usr/local/lib/libabsl_vlog_config_internal.a
image_client: /usr/local/lib/libabsl_log_internal_fnmatch.a
image_client: /usr/local/lib/libabsl_random_distributions.a
image_client: /usr/local/lib/libabsl_random_seed_sequences.a
image_client: /usr/local/lib/libabsl_random_internal_pool_urbg.a
image_client: /usr/local/lib/libabsl_random_internal_randen.a
image_client: /usr/local/lib/libabsl_random_internal_randen_hwaes.a
image_client: /usr/local/lib/libabsl_random_internal_randen_hwaes_impl.a
image_client: /usr/local/lib/libabsl_random_internal_randen_slow.a
image_client: /usr/local/lib/libabsl_random_internal_platform.a
image_client: /usr/local/lib/libabsl_random_internal_seed_material.a
image_client: /usr/local/lib/libabsl_random_seed_gen_exception.a
image_client: /usr/local/lib/libabsl_statusor.a
image_client: /usr/local/lib/libabsl_status.a
image_client: /usr/local/lib/libabsl_strerror.a
image_client: /usr/local/lib/libutf8_validity.a
image_client: /usr/local/lib/libabsl_flags_usage.a
image_client: /usr/local/lib/libabsl_flags_usage_internal.a
image_client: /usr/local/lib/libabsl_flags_internal.a
image_client: /usr/local/lib/libabsl_flags_marshalling.a
image_client: /usr/local/lib/libabsl_flags_reflection.a
image_client: /usr/local/lib/libabsl_flags_config.a
image_client: /usr/local/lib/libabsl_flags_program_name.a
image_client: /usr/local/lib/libabsl_flags_private_handle_accessor.a
image_client: /usr/local/lib/libabsl_flags_commandlineflag.a
image_client: /usr/local/lib/libabsl_flags_commandlineflag_internal.a
image_client: /usr/local/lib/libabsl_cord.a
image_client: /usr/local/lib/libabsl_cordz_info.a
image_client: /usr/local/lib/libabsl_cord_internal.a
image_client: /usr/local/lib/libabsl_cordz_functions.a
image_client: /usr/local/lib/libabsl_cordz_handle.a
image_client: /usr/local/lib/libabsl_crc_cord_state.a
image_client: /usr/local/lib/libabsl_crc32c.a
image_client: /usr/local/lib/libabsl_str_format_internal.a
image_client: /usr/local/lib/libabsl_crc_internal.a
image_client: /usr/local/lib/libabsl_crc_cpu_detect.a
image_client: /usr/local/lib/libabsl_raw_hash_set.a
image_client: /usr/local/lib/libabsl_hash.a
image_client: /usr/local/lib/libabsl_bad_variant_access.a
image_client: /usr/local/lib/libabsl_city.a
image_client: /usr/local/lib/libabsl_low_level_hash.a
image_client: /usr/local/lib/libabsl_bad_optional_access.a
image_client: /usr/local/lib/libabsl_hashtablez_sampler.a
image_client: /usr/local/lib/libabsl_exponential_biased.a
image_client: /usr/local/lib/libabsl_synchronization.a
image_client: /usr/local/lib/libabsl_graphcycles_internal.a
image_client: /usr/local/lib/libabsl_kernel_timeout_internal.a
image_client: /usr/local/lib/libabsl_time.a
image_client: /usr/local/lib/libabsl_civil_time.a
image_client: /usr/local/lib/libabsl_time_zone.a
image_client: /usr/local/lib/libabsl_stacktrace.a
image_client: /usr/local/lib/libabsl_symbolize.a
image_client: /usr/local/lib/libabsl_strings.a
image_client: /usr/local/lib/libabsl_strings_internal.a
image_client: /usr/local/lib/libabsl_string_view.a
image_client: /usr/local/lib/libabsl_int128.a
image_client: /usr/local/lib/libabsl_throw_delegate.a
image_client: /usr/local/lib/libabsl_malloc_internal.a
image_client: /usr/local/lib/libabsl_debugging_internal.a
image_client: /usr/local/lib/libabsl_demangle_internal.a
image_client: /usr/local/lib/libabsl_base.a
image_client: /usr/local/lib/libabsl_raw_logging_internal.a
image_client: /usr/local/lib/libabsl_log_severity.a
image_client: /usr/local/lib/libabsl_spinlock_wait.a
image_client: CMakeFiles/image_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/goshan9/web-labs/web-labs/image_service/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable image_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image_client.dir/build: image_client
.PHONY : CMakeFiles/image_client.dir/build

CMakeFiles/image_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image_client.dir/clean

CMakeFiles/image_client.dir/depend:
	cd /home/goshan9/web-labs/web-labs/image_service && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/goshan9/web-labs/web-labs/image_service /home/goshan9/web-labs/web-labs/image_service /home/goshan9/web-labs/web-labs/image_service /home/goshan9/web-labs/web-labs/image_service /home/goshan9/web-labs/web-labs/image_service/CMakeFiles/image_client.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/image_client.dir/depend
