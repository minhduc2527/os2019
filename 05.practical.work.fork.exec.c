duc@duc-Inspiron-5570:~$ grep system /proc/sched_debug
 S systemd-logind   820         9.442553       523   120         0.000000        46.801744         0.000000 0 0 /autogroup-45
 S  systemd-udevd   332       316.467443       439   120         0.000000       264.177053         0.000000 0 0 /autogroup-16
 Ssystemd-timesyn   680        13.274380       190   120         0.000000        33.123532         0.000000 0 0 /autogroup-37
 S        systemd  1059         2.827332        21   120         0.000000        20.436334         0.000000 0 0 /autogroup-74
 S        systemd     1       206.842491      1899   120         0.000000      1592.222545         0.000000 0 0 /autogroup-2
 Ssystemd-journal   299        89.122546      1618   120         0.000000       475.478757         0.000000 0 0 /autogroup-5

duc@duc-Inspiron-5570:~$ grep system /proc/1059/sched
systemd (1059, #threads: 1)

duc@duc-Inspiron-5570:~$ grep switch /proc/1059/sched
nr_switches                                  :                   21
nr_voluntary_switches                        :                   20
nr_involuntary_switches                      :                    1

duc@duc-Inspiron-5570:~$ grep switch /proc/1/sched
nr_switches                                  :                 1902
nr_voluntary_switches                        :                 1613
nr_involuntary_switches                      :                  289

