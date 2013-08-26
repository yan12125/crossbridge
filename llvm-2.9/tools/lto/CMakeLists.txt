set(EXPORTED_SYMBOL_FILE $(PROJ_SRC_DIR)/lto.exports)

add_llvm_library(LTO
  LTOModule.cpp
  LTOCodeGenerator.cpp
  lto.cpp
)

target_link_libraries(LTO LLVMMC LLVMSupport)# LLVMAnalysis LLVMArchive LLVMAsmParser LLVMAsmPrinter LLVMAVM2ShimCodeGen LLVMAVM2ShimInfo LLVMBitReader LLVMBitWriter LLVMCodeGen LLVMCore LLVMExecutionEngine LLVMInstCombine LLVMInstrumentation LLVMInterpreter LLVMipa LLVMipo LLVMJIT LLVMLinker LLVMMCDisassembler LLVMMCJIT LLVMCBackend LLVMCBackendInfo LLVMMCParser LLVMObject LLVMScalarOpts LLVMSelectionDAG LLVMTarget LLVMTransformUtils LLVMX86AsmParser LLVMX86AsmPrinter LLVMX86CodeGen LLVMX86Disassembler LLVMX86Info LLVMX86Utils)
