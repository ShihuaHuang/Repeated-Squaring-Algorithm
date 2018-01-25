plot(computation_time_exponent(:,1,1),computation_time_exponent(:,2,1),computation_time_exponent(:,1,1),computation_time_exponent(:,3,1))
xlabel('Exponent');
ylabel('Computation Time');
title('Computation Time vs. Exponent Plot');
legend('Repeated Squares','Brute Force Multiplication')

plot(computation_time_size(:,1,1),computation_time_size(:,2,1),computation_time_size(:,1,1),computation_time_size(:,3,1))
xlabel('Matrix Size');
ylabel('Computation Time');
title('Computation Time vs. Matrix Size Plot');
legend('Repeated Squares','Brute Force Multiplication')