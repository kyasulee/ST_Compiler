PROGRAM Example
    VAR
        x INT := 10;
        y BOOL;
    END_VAR

    x := 10;  // 赋值语句
    z := 10;  // 报错：Error: Undefined variable: z
    IF x > 5 THEN  // 选择语句
        x := x + 1;
    END_IF;

    WHILE x < 10 DO  // 迭代语句
        x := x + 1;
    END_WHILE;

    Add(x, y);  // 函数调用语句
    RETURN;     // 跳转语句
END_PROGRAM

FUNCTION Add : INT
VAR_INPUT
    a INT;
    b INT;
END_VAR
Add := a + b;
END_FUNCTION

FUNCTION_BLOCK MyFB
VAR
    inputVar INT;
    outputVar INT;
END_VAR
outputVar := inputVar + 1;
END_FUNCTION_BLOCK