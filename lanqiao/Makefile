# Makefile in subdirectory

# 获取当前文件夹中的所有源文件
    SOURCES := $(wildcard *.cpp)
# 生成可执行文件的名称（假设只有一个源文件）
    EXECUTABLE := $(basename $(SOURCES))

# 默认目标是生成可执行文件
    all: $(EXECUTABLE)

# 生成可执行文件的规则
    $(EXECUTABLE): $(SOURCES)
        $(CXX) $(CXXFLAGS) -o $@ $^

# 清理目标
    clean:
        rm -f $(EXECUTABLE)
