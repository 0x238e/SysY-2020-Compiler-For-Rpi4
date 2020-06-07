; ModuleID = 'test.ll'
source_filename = "test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@arr = dso_local global [4 x i32] [i32 1, i32 2, i32 3, i32 4], align 16
@a = dso_local global i32 1234, align 4

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local i32 @fib(i32 %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  %4 = load i32, i32* %3, align 4
  %5 = icmp sle i32 %4, 2
  br i1 %5, label %6, label %7

6:                                                ; preds = %1
  store i32 1, i32* %2, align 4
  br label %15

7:                                                ; preds = %1
  %8 = load i32, i32* %3, align 4
  %9 = sub nsw i32 %8, 1
  %10 = call i32 @fib(i32 %9)
  %11 = load i32, i32* %3, align 4
  %12 = sub nsw i32 %11, 2
  %13 = call i32 @fib(i32 %12)
  %14 = add nsw i32 %10, %13
  store i32 %14, i32* %2, align 4
  br label %15

15:                                               ; preds = %7, %6
  %16 = load i32, i32* %2, align 4
  ret i32 %16
}

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %5 = load i32, i32* @a, align 4
  %6 = sub nsw i32 0, %5
  store i32 %6, i32* %2, align 4
  %7 = load i32, i32* @a, align 4
  %8 = add nsw i32 %7, 1
  store i32 %8, i32* @a, align 4
  %9 = load i32, i32* @a, align 4
  %10 = sub nsw i32 %9, 2
  store i32 %10, i32* @a, align 4
  %11 = load i32, i32* @a, align 4
  %12 = mul nsw i32 %11, 3
  store i32 %12, i32* @a, align 4
  %13 = load i32, i32* @a, align 4
  %14 = sdiv i32 %13, 4
  store i32 %14, i32* @a, align 4
  %15 = load i32, i32* @a, align 4
  %16 = srem i32 %15, 5
  store i32 %16, i32* @a, align 4
  %17 = load i32, i32* @a, align 4
  %18 = icmp sgt i32 %17, 0
  br i1 %18, label %19, label %21

19:                                               ; preds = %0
  %20 = load i32, i32* @a, align 4
  store i32 %20, i32* %2, align 4
  br label %29

21:                                               ; preds = %0
  %22 = load i32, i32* @a, align 4
  %23 = icmp eq i32 %22, 0
  br i1 %23, label %24, label %25

24:                                               ; preds = %21
  store i32 0, i32* %2, align 4
  br label %28

25:                                               ; preds = %21
  %26 = load i32, i32* @a, align 4
  %27 = sub nsw i32 0, %26
  store i32 %27, i32* %2, align 4
  br label %28

28:                                               ; preds = %25, %24
  br label %29

29:                                               ; preds = %28, %19
  %30 = load i32, i32* %2, align 4
  %31 = icmp sgt i32 %30, 0
  br i1 %31, label %32, label %._crit_edge

._crit_edge:                                      ; preds = %29
  br label %35

32:                                               ; preds = %29
  %33 = load i32, i32* %2, align 4
  %34 = call i32 @fib(i32 %33)
  store i32 %34, i32* %2, align 4
  br label %35

35:                                               ; preds = %._crit_edge, %32
  %36 = load i32, i32* @a, align 4
  %37 = load i32, i32* %2, align 4
  %38 = add nsw i32 %36, %37
  store i32 %38, i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i64 0, i64 3), align 4
  store i32 10, i32* %3, align 4
  store i32 0, i32* %4, align 4
  br label %39

39:                                               ; preds = %42, %35
  %40 = load i32, i32* %3, align 4
  %41 = icmp sgt i32 %40, 0
  br i1 %41, label %42, label %48

42:                                               ; preds = %39
  %43 = load i32, i32* %4, align 4
  %44 = load i32, i32* %3, align 4
  %45 = add nsw i32 %43, %44
  store i32 %45, i32* %4, align 4
  %46 = load i32, i32* %3, align 4
  %47 = sub nsw i32 %46, 1
  store i32 %47, i32* %3, align 4
  br label %39

48:                                               ; preds = %39
  %49 = load i32, i32* %4, align 4
  %50 = load i32, i32* getelementptr inbounds ([4 x i32], [4 x i32]* @arr, i64 0, i64 3), align 4
  %51 = add nsw i32 %49, %50
  ret i32 %51
}

attributes #0 = { noinline nounwind optnone sspstrong uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{!"clang version 10.0.0 "}
