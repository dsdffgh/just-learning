位置式PID：u(k)=Kp * e(k)+Ki / T * ∫ e(k) dt+Kd*d e(k)；

增量式PID：u(k)=Kp * e(k-1)+Ki *e(t) +Kd *(e(k)-2e(k-1)+e(k-2))；

很显然，对位置式PID进行求导（dx = f(x) - f(x-1)），就得到了增量式PID。

离散化之后：

位置式PID: $$ u[k] = K_p * e[k] + K_i * \sum_{j=0}^k e_j + K_d (e_k-e_{k-1}) $$

增量式PID: \delta{u[k]}

### clamping
1. The output is asturating
2. The error is the same sign as the controller output
