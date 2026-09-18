/*
 * Lesson 07a: 求 100 以内的最大素数
 *
 * 知识点：math.h, sqrt, 强制类型转换 (int), 三层逻辑嵌套
 *
 * 任务：参考原课 prime.c，完成素数判定：
 *       1. 外层 for num 从 1 到 100
 *       2. 计算 tmp=(int)sqrt((double)num)
 *       3. 内层 for i 从 2 到 tmp，判断 num % i == 0 则 break
 *       4. 如果 i == tmp + 1，说明 num 是素数，更新 max
 *       5. 最后打印 "max prime is %d\n"
 *
 * 课堂讨论：j == tmp + 1 能否改为 j == tmp? 为什么？
 *           如果没有数学库，这个程序如何编写效率才能最高？
 *
 * 验证：stdout 精确匹配 "max prime is 97\n"
 */

#include <math.h>
#include <stdio.h>

int main(void) {
    int num;
    int i;
    int max = 0;
	int tmp = 0;
    for(num=2;num<=100;num++){
		tmp=(int)sqrt((double)num);//找公因数不用找到num-1，找到他的平方根就可以
		//此处double是为了满足sqrt对数字浮点的要求，int则是为了取整
		for(i=2;i<=tmp;i++){
			if(num%i==0){
				break;
			}
		}
		if(num>1&&i==tmp+1)//这样就证明num经历完了循环并没有被踢出，这样他就肯定是素数
		{
			max=num;//直到最后素数不断被更新，也就找到了最大的那一个
		}
	}
    printf("max prime is %d\n", max);
    return 0;
}
