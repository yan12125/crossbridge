set(LLVM_LINK_COMPONENTS ${LLVM_TARGETS_TO_BUILD} bitreader asmparser)

add_llvm_tool(llc
  llc.cpp
  )

target_link_libraries(llc uuid)
