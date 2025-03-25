PROGRAM Example
    VAR
        x : INT;
        y : INT;
    END_VAR

    x := 10;  // 赋值语句
    IF x > 5 THEN  // 选择语句
        x := x + 1;
    END_IF;

    WHILE x < 10 DO  // 迭代语句
        x := x + 1;
    END_WHILE;

    Add(x, y);  // 函数调用语句
    RETURN;     // 跳转语句
END_PROGRAM