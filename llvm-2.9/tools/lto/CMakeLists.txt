# set(EXPORTED_SYMBOL_FILE $(PROJ_SRC_DIR)/lto.exports)

# add_llvm_library(LTO
#   LTOModule.cpp
#   LTOCodeGenerator.cpp
#   lto.cpp
# )

# target_link_libraries(LTO LLVMMC LLVMSupport LLVMTarget LLVMCore LLVMipa LLVMAnalysis LLVMArchive LLVMAsmParser LLVMAsmPrinter LLVMAVM2ShimCodeGen LLVMAVM2ShimInfo LLVMBitReader LLVMBitWriter LLVMCodeGen LLVMExecutionEngine LLVMInstCombine LLVMInstrumentation LLVMInterpreter LLVMipo LLVMJIT LLVMLinker LLVMMCDisassembler LLVMMCJIT LLVMCBackend LLVMCBackendInfo LLVMMCParser LLVMObject LLVMScalarOpts LLVMSelectionDAG LLVMTransformUtils LLVMX86AsmParser LLVMX86AsmPrinter LLVMX86CodeGen LLVMX86Disassembler LLVMX86Info LLVMX86Utils)
# if( LLVM_ENABLE_THREADS AND HAVE_LIBPTHREAD )
#     target_link_libraries(LTO pthread)
# endif()

set(LLVM_LINK_COMPONENTS
  ${LLVM_TARGETS_TO_BUILD}
  ipo scalaropts linker bitreader bitwriter mcdisassembler vectorize)

add_definitions( -DLLVM_VERSION_INFO=\"${PACKAGE_VERSION}\" )

set(SOURCES
  LTOCodeGenerator.cpp
  lto.cpp
  LTOModule.cpp
  )

#if( NOT WIN32 AND LLVM_ENABLE_PIC )
#  set(bsl ${BUILD_SHARED_LIBS})
#  set(BUILD_SHARED_LIBS ON)
#  add_llvm_library(LTO ${SOURCES})
#  set_property(TARGET LTO PROPERTY OUTPUT_NAME "LTO")
#  set(BUILD_SHARED_LIBS ${bsl})
#  set(LTO_STATIC_TARGET_NAME LTO_static)
#else()
#  set(LTO_STATIC_TARGET_NAME LTO)
#endif()
set(LTO_STATIC_TARGET_NAME LTO)

if( NOT BUILD_SHARED_LIBS )
  add_llvm_library(${LTO_STATIC_TARGET_NAME} ${SOURCES})
  set_property(TARGET ${LTO_STATIC_TARGET_NAME} PROPERTY OUTPUT_NAME "LTO")
endif()


set(EXPORTED_SYMBOL_FILE $(PROJ_SRC_DIR)/lto.exports)

