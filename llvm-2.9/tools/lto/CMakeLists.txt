set(EXPORTED_SYMBOL_FILE $(PROJ_SRC_DIR)/lto.exports)

add_llvm_library(LTO
  LTOModule.cpp
  LTOCodeGenerator.cpp
  lto.cpp
)

target_link_libraries(LTO LLVMMC LLVMSupport LLVMTarget LLVMCore LLVMipa LLVMAnalysis)# LLVMArchive LLVMAsmParser LLVMAsmPrinter LLVMAVM2ShimCodeGen LLVMAVM2ShimInfo LLVMBitReader LLVMBitWriter LLVMCodeGen LLVMExecutionEngine LLVMInstCombine LLVMInstrumentation LLVMInterpreter LLVMipo LLVMJIT LLVMLinker LLVMMCDisassembler LLVMMCJIT LLVMCBackend LLVMCBackendInfo LLVMMCParser LLVMObject LLVMScalarOpts LLVMSelectionDAG LLVMTransformUtils LLVMX86AsmParser LLVMX86AsmPrinter LLVMX86CodeGen LLVMX86Disassembler LLVMX86Info LLVMX86Utils)
if( LLVM_ENABLE_THREADS AND HAVE_LIBPTHREAD )
    target_link_libraries(LTO pthread)
endif()

