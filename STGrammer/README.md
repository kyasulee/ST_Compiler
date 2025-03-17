# 安装antlr4步骤

首先需要检查是否有java环境
```
java -version
```

没有的话
```
sudo apt install openjdk-17-jdk
```

装好java环境之后，先下载antlr-4.9.3-complete.jar
```
wget https://www.antlr.org/download/antlr-4.9.3-complete.jar
```
可以考虑放到系统lib中方便全局使用（但我没放）

接下来配置环境变量
```
export CLASSPATH=“/root/codes/llvm/st_builder/STGrammer/antlr-4.9.3-complete.jar:$CLASSPATH”
alias antlr4='java -jar /root/codes/llvm/st_builder/STGrammer/antlr-4.9.3-complete.jar'
alias grun='java org.antlr.v4.gui.TestRig'
source ~/.bashrc
```
输入antlr4有版本信息就是装好了
