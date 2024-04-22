import matplotlib.pyplot as plt

class ApplicationWithKpKi:
    def __init__(self, ex=1, current=0.2, kp=0.5, ki=0.05):
        self.ex = ex
        self.current = current
        self.kp = kp
        self.ki = ki
        self.error = self.ex - self.current
        self.error_acc = self.error # error accumulation
        self.iterate_times = 0

        self.output_list = [self.current]
        self.error_list = [self.error]

    def run(self):
        self.iterate(50)
        self.plot()
        print(self.output_list)
        print("[info] iterate times: ", self.iterate_times)

    def iterate(self, epoch):
        """ iterate to update current, error """
        for i in range(epoch):
            # 加水量u
            u = self.kp * self.error + self.ki * self.error_acc
            self.current += u
            self.output_list.append(self.current)
            self.error_list.append(self.error)
            self.error = self.ex - self.current
            self.error_acc += self.error
            # if self.current >= self.ex:
            #     self.iterate_times = i
            #     return
            self.iterate_times = epoch

    def plot(self):
        l1, = plt.plot(list(range(len(self.output_list))), self.output_list, label='output')
        l2, = plt.plot(list(range(len(self.error_list))), self.error_list, label='error', linestyle='--', color='r')
        l3 = plt.plot(list(range(len(self.output_list))), [1] * len(self.output_list), linestyle='--', color='g'  )
        plt.xlabel('times / s')
        plt.ylabel('water volume / (m^3)')
        plt.legend(handles=[l1, l2],
                   labels = ['output', 'error'])
        plt.show()

if __name__ == '__main__':
    app = ApplicationWithKpKi(kp=0.5, ki=0.05)
    app.run()
