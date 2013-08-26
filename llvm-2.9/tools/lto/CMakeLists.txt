set(EXPORTED_SYMBOL_FILE $(PROJ_SRC_DIR)/lto.exports)

add_llvm_library(LTO
  LTOModule.cpp
  LTOCodeGenerator.cpp
  lto.cpp
)

target_link_libraries(LTO LLVMMC LLVMSupport)
