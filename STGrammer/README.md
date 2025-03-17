# Steps to install antlr4

First, you need to check whether there is a java environment:
```
java -version
```
If not, you need:
```
sudo apt install openjdk-17-jdk
```
After installing the java environment, you need to download antlr-4.9.3-complete.jar:
```
wget https://www.antlr.org/download/antlr-4.9.3-complete.jar
```
Next, configure the environment variables:
```
export CLASSPATH=“/root/codes/llvm/st_builder/STGrammer/antlr-4.9.3-complete.jar:$CLASSPATH”
alias antlr4='java -jar /root/codes/llvm/st_builder/STGrammer/antlr-4.9.3-complete.jar'
alias grun='java org.antlr.v4.gui.TestRig'
source ~/.bashrc
```
Enter `antlr4` in the terminal and there is version information, which means it is installed.
