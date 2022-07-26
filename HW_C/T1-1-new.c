//
//  T1-1-new.c
//  c
//
//  Created by Xinyu Zhang on 22/12/2021.
//
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永無BUG
//
//
//
//
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/msg.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<string.h>
#include <signal.h>
struct square{
    double p[2];
    double side;
};

int main(int argc, const char *argv[]){
    enum {size = 2};
    struct square calc[size];
    float halfside1, diff1, diff2;
    int counter;
    for (counter = 0; counter < size; counter++){
        scanf("%lf %lf %lf", &calc[counter].p[0], &calc[counter].p[1], &calc[counter].side);
    }
    
    halfside1 = (calc[0].side + calc[1].side)/2;
    diff1 = calc[0].p[0] - calc[1].p[0];
    diff2 = calc[0].p[1] - calc[1].p[1];
    
    if (diff1 < 0){
        diff1 = -diff1;
    }
    if (diff2 < 0){
        diff2 = -diff2;
    }
    
//    printf("%g %g\n", diff1, diff2);
    
    if ((diff1 > halfside1) && (diff2 > halfside1)){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    
    
    
    
    return 0;
}
