; ModuleID = 'test.c'
source_filename = "test.c"
target datalayout = "e-m:w-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.25.28614"

@arr = dso_local global [4 x i32] [i32 1, i32 2, i32 3, i32 4], align 16
@a = dso_local global i32 1234, align 4

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @fib(i32 %n) #0 {
entry:
  %retval = alloca i32, align 4
  %n.addr = alloca i32, align 4
  store i32 %n, i32* %n.addr, align 4
  %0 = load i32, i32* %n.addr, align 4
  %cmp = icmp sle i32 %0, 2
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  store i32 1, i32* %retval, align 4
  br label %return

if.else:                                          ; preds = %entry
  %1 = load i32, i32* %n.addr, align 4
  %sub = sub nsw i32 %1, 1
  %call = call i32 @fib(i32 %sub)
  %2 = load i32, i32* %n.addr, align 4
  %sub1 = sub nsw i32 %2, 2
  %call2 = call i32 @fib(i32 %sub1)
  %add = add nsw i32 %call, %call2
  store i32 %add, i32* %retval, align 4
  br label %return

return:                                           ; preds = %if.else, %if.then
  %3 = load i32, i32* %retval, align 4
  ret i32 %3
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %b = alloca i32, align 4
  %c = alloca i32, align 4
  %sum = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  %0 = load i32, i32* @a, align 4
  %sub = sub nsw i32 0, %0
  store i32 %sub, i32* %b, align 4
  %1 = load i32, i32* @a, align 4
  %add = add nsw i32 %1, 1
  store i32 %add, i32* @a, align 4
  %2 = load i32, i32* @a, align 4
  %sub1 = sub nsw i32 %2, 2
  store i32 %sub1, i32* @a, align 4
  %3 = load i32, i32* @a, align 4
  %mul = mul nsw i32 %3, 3
  store i32 %mul, i32* @a, align 4
  %4 = load i32, i32* @a, align 4
  %div = sdiv i32 %4, 4
  store i32 %div, i32* @a, align 4
  %5 = load i32, i32* @a, align 4
  %rem = srem i32 %5, 5
  store i32 %rem, i32* @a, align 4
  %6 = load i32, i32* @a, align 4
  %cmp = icmp sgt i32 %6, 0
  br i1 %cmp, label %if.then, label %if.else

if.then:                                          ; preds = %entry
  %7 = load i32, i32* @a, align 4
  store i32 %7, i32* %b, align 4
  br label %if.end6

if.else:                                          ; preds = %entry
  %8 = load i32, i32* @a, align 4
  %cmp2 = icmp eq i32 %8, 0
  br i1 %cmp2, label %if.then3, label %if.else4

if.then3:                                         ; preds = %if.else
  store i32 0, i32* %b, align 4
  br label %if.end

if.else4:                                         ; preds = %if.else
  %9 = load i32, i32* @a, align 4
  %sub5 = sub nsw i32 0, %9
  store i32 %sub5, i32* %b, align 4
  br label %if.end

if.end:                                           ; preds = %if.else4, %if.then3
  br label %if.end6

if.end6:                                          ; preds = %if.end, %if.then
  %10 = load i32, i32* %b, align 4
  %cmp7 = icmp sgt i32 %10, 0
  br i1 %cmp7, label %if.then8, label %if.end9

if.then8:                                         ; preds = %if.end6
  %11 = load i32, i32* %b, align 4
  %call = call i32 @fib(i32 %11)
  store i32 %call, i32* %b, align 4
  br label %if.end9

if.end9:                                          ; preds = %if.then8, %if.end6
  %12 = load i32, i32* @a, align 4
  %13 = load i32, i32* %b, align 4
  %add10 = add nsw i32 %12, %13
  store i32 %add10, i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i64 0, i64 3), align 4
  store i32 10, i32* %c, align 4
  store i32 0, i32* %sum, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.end9
  %14 = load i32, i32* %c, align 4
  %cmp11 = icmp sgt i32 %14, 0
  br i1 %cmp11, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %15 = load i32, i32* %sum, align 4
  %16 = load i32, i32* %c, align 4
  %add12 = add nsw i32 %15, %16
  store i32 %add12, i32* %sum, align 4
  %17 = load i32, i32* %c, align 4
  %sub13 = sub nsw i32 %17, 1
  store i32 %sub13, i32* %c, align 4
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %18 = load i32, i32* %sum, align 4
  %19 = load i32, i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i64 0, i64 3), align 4
  %add14 = add nsw i32 %18, %19
  ret i32 %add14
}

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{!"clang version 8.0.0 (trunk)"}
