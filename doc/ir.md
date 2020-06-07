# 类型

## 基本类型

- void

  对应 void

- i32

  对应 int

- i1

  对应关系表达式的运算结果，不用于数组内

- i8

  只用于全局的一维数组常量，对应运行时调用传入的字符串参数

- label

  用于控制流时表明接下来的变量是label

## 数组

表达形式：

array_type -> int_array_type | [`n` x i8]

int_array_type -> [`n` x i32] | [`n` x int_array_type]

（只是与 llvm 表示数组的方式相同，实际实现不需要“parse”）

`n` 为一个整数字面量，代表此维度的大小

例如：

`"string"` 类型为 [7 x i8] （要算上\0)

`{{1, 2}, {3, 4}, {5, 6}}` 类型为 [3 x [2 x i32]]

## 指针

表达形式：

pointer_type = int_array_type* | i32* | pointer_type*

主要用于函数传参时，例如：

`void test(int a[][2], int b[][3][4]) { }`

a 的类型为 [2 x i32]*

b 的类型为 [3 x [4 x i32]]*

# 全局变量以及常量

## 全局常量

所有要放入 .data 段的常量，包括函数内的字面量

语法：

`@<name> = constant <type> <init>`

---

```
<int_value> -> i32 <num>

<int_array_value> -> <type> [<value>{, <value>}]
                   | [<int_array_value>{, <int_array_value>}]
                   | <type> zeroinitializer

<string_value> -> "some_string"

<init> -> <int_value>
        | <int_array_value>
        | <string_value>
```

写的比较乱.. 看例子理解一下吧 基本和 llvm 保持一致（去掉了一些修饰符和 align）

{!review}
`@<name>` 实则为指针类型

例如：

- `"%d"`（字面量，没有显式声明）

  `@str_const_0 = constant [3 x i8] "%d\0"`

- `const int a[4][2] = {};`

  `@a = constant [4 x [2 x i32]] zeroinitializer`

- `const int b[4][2] = {1,2,3,4,5,6,7,8};`

  `@b = constant [4 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 4], [2 x i32] [i32 5, i32 6], [2 x i32] [i32 7, i32 8]]`

- `const int c[4][2] = {{1,2},{3,4},5,6,7,8};`

  `@c = constant [4 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 4], [2 x i32] [i32 5, i32 6], [2 x i32] [i32 7, i32 8]]`

- `const int d[4][2] = {1,2,{3},{5},7,8};`

  `@d = constant [4 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 0], [2 x i32] [i32 5, i32 0], [2 x i32] [i32 7, i32 8]]`

- `const int e[4][2] = {{1,2},{3,4},{5,6},{}};`

  `@e = constant [4 x [2 x i32]] [[2 x i32] [i32 1, i32 2], [2 x i32] [i32 3, i32 4], [2 x i32] [i32 5, i32 6], [2 x i32] zeroinitializer]`

## 全局变量

语法：

`@<name> = global <type> <init>`

---

{!review}
这边可能有一个疑问是 init 如果引用其他全局变量怎么办。如果引用全局常量，就直接替换成字面量。
[Const]InitVal 应该在parsing到ir的时候把初始值求出来了吧。
# 函数

语法：

```
define <ret_type> @<name>(<type_list>) {
  <body>
}
```

---

```
<ret_type> -> void | int

<type_list> -> <type>{, <type>}
```

例如 `void test(int a, int b[][2], c[][3][4]) { }`

```
define void @test(i32, [2 x i32]*, [3 x [4 x i32]]*) {
  %4 = alloca [3 x [4 x i32]]*
  %5 = alloca [2 x i32]*
  %6 = alloca i32
  store [3 x [4 x i32]]* %2, [3 x [4 x i32]]** %4
  store [2 x i32]* %1, [2 x i32]** %5
  store i32 %0, i32* %6
  ret void
}
```

{!review}
这个是 llvm 的结果，llvm 的定义是参数不具名，默认为 %0, %1, %2... 只读 然后局部变量做一个拷贝，命名跳一个开始（我也不知道为啥）（edit: 可能是开始块隐含的 label 占用了）。看看需不需要简化一下。

putf这样的变长函数，ir里面是否需要特殊处理？

# 指令

## 内存相关

### alloca

```
%ptr = alloca <type>
```

在栈上分配 `sizeof(<type>)` 大小的内存，地址放入 `%ptr`。`%ptr` 的类型为 `<type>*`。

### load

```
%val = load <val_type>, <ptr_type> %ptr
```

{!review}
从 `%ptr` 所指向的内存 load `sizeof(<val_type>)` 并放入 `%val`。类型必须对应。（一般只有 i32，调用 putf 的时候可能要小心一下）。
如果我没有理解错的话，putf一个string大概长这样？
```
@str = global [6 x i8] "hello"

call void @putf([6 x i8]* @str, ...)
```


### store

```
store <val_type> <value>, <ptr_type> %ptr
store <val_type> %val, <ptr_type> %ptr
```

将 `<value>` 或者 `%val` 存入 `%ptr` 所指向的内存。类型必须对应。

### 其他

{!review}
考虑一下在数组寻址的时候以及其他情况是否需要别的指令，比如 `getelementptr` 等。

## 算数运算

### add

```
%result = add i32 <op1>, <op2>
```

`<op1>` 和 `<op2>` 可以是字面量或者变量。

`%result = <op1> + <op2>`

### sub

```
%result = sub i32 <op1>, <op2>
```

`<op1>` 和 `<op2>` 可以是字面量或者变量。

`%result = <op1> - <op2>`

### mul

```
%result = mul i32 <op1>, <op2>
```

`<op1>` 和 `<op2>` 可以是字面量或者变量。

`%result = <op1> *+* <op2>`

### sdiv

```
%result = sdiv i32 <op1>, <op2>
```

`<op1>` 和 `<op2>` 可以是字面量或者变量。

`%result = <op1> / <op2>`

### srem

```
%result = srem i32 <op1>, <op2>
```

`<op1>` 和 `<op2>` 可以是字面量或者变量。

`%result = <op1> % <op2>`

## 控制流

### label

```
<label_name>:
```

指定一个名字为 `<label_name>` 的 label。

### ret

```
ret void
ret i32 <value>
ret i32 %val
```

### br

```
br lable %label
br i1 0/1, label %ltrue, label %lfalse
br i1 %cond, label %ltrue, label %lfalse
```

### icmp

```
%result = icmp <cond> i32 <op1>, <op2>

<cond> -> eq    # equal
        | ne    # not equal
        | sgt   # greater
        | sge   # greater or equal
        | slt   # less
        | sle   # less or equal
```

`%result` 类型为 `i1`。

{!review}
是否需要一个函数调用的指令call？

{!review}
llvm 的逻辑运算实现为通过跳转的形式。我们遵循这样的模式还是创造新的 op？
sysy里面的逻辑运算只会出现在if或者while的条件判断里面，不会作为expr出现，要不就遵循这模式吧。

例子：

```
int a = 0;

void test() {
  if ((a == 0) && (a == 1)) {
    a = 2;
  }
}
```

的 llvm ir 为

```
@a = dso_local global i32 0, align 4

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @test() #0 {
  %1 = load i32, i32* @a, align 4
  %2 = icmp eq i32 %1, 0
  br i1 %2, label %3, label %7

; <label>:3:                                      ; preds = %0
  %4 = load i32, i32* @a, align 4
  %5 = icmp eq i32 %4, 1
  br i1 %5, label %6, label %7

; <label>:6:                                      ; preds = %3
  store i32 2, i32* @a, align 4
  br label %7

; <label>:7:                                      ; preds = %6, %3, %0
  ret void
}
```

### phi

```
%result = phi <type> [<value_1>, %label_1], [<value_2>, %label_2]{, [<value_n>, %label_n]}
```

`<type>` 是所有 value 以及 result 的 type。

如果是从 `%label_i` 执行到这个 basic block，则 `%result = <value_i>`。

### call

```
call void @func(<type_1> <arg_1>{, <type_n> <arg_n>})
%result = call i32 @func(<type_1> <arg_1>{, <type_n> <arg_n>})
```
