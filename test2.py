import matplotlib.pyplot as plt
import numpy as np

e5r1 = [43.57,
38.21,
40.64,
55.21,
56.28]

e5r2 = [55.26,
49.49,
52.11,
68.77,
69.55]

e5r5 = [69.19,
64.31,
67.00,
82.33,
83.06]

e5r10 = [78.31,
74.13,
76.76,
89.71,
90.32]

e15r1 = [39.72,
39.43,
40.58,
43.44,
42.94,
43.11,
44.07,
44.36,
44.30,
44.68,
43.74,
44.94,
44.84,
44.97,
44.91]

e15r2 = [51.53,
51.22,
52.40,
56.00,
55.21,
55.22,
56.76,
56.75,
56.81,
57.14,
55.94,
57.39,
57.11,
57.30,
57.26]

e15r5 = [65.81,
65.92,
67.58,
71.08,
70.26,
70.42,
71.91,
72.15,
71.98,
72.38,
70.76,
72.23,
72.01,
72.10,
72.04]

e15r10 = [75.90,
76.05,
77.66,
80.82,
80.28,
79.93,
81.28,
81.49,
81.39,
81.50,
80.02,
81.21,
81.29,
81.24,
81.30]

mr1 = [4.12,
5.11,
5.49,
5.54,
5.54]

mr2 = [6.31,
7.61,
8.67,
8.49,
8.46]

mr5 = [10.79,
12.95,
14.76,
14.06,
14.03]

mr10 = [15.87,
19.30,
20.82,
19.81,
19.99]

m14r1 = [
    04.5499021526418784,
    05.3082191780821915,
    05.8341487279843444,
    06.029843444227006,
    06.335616438356165,
    05.895303326810176,
    05.8341487279843444,
    05.968688845401174,
    05.931996086105675,
    05.944227005870841,
    05.711839530332681,
    05.931996086105675,
    05.711839530332681,
    05.7729941291585124
]

m15r1 = [
    04.24412915851272,
    05.1492172211350294,
    05.552837573385518,
    05.7607632093933464,
    05.968688845401174,
    05.8341487279843444,
    05.3816046966731895,
    05.491682974559687,
    05.785225048923679,
    05.283757338551859,
    05.47945205479452,
    05.5283757338551856,
    05.503913894324853,
    05.577299412915851,
    05.503913894324853
]


fig, ax = plt.subplots()

# ax.plot(np.arange(5), e5r1, color='tab:blue', label="5 эпох")
# ax.plot(np.arange(5), e5r2, color='tab:blue')
# ax.plot(np.arange(5), e5r5, color='tab:blue')
# ax.plot(np.arange(5), e5r10, color='tab:blue')

# ax.plot(np.arange(15), e15r1, color='tab:orange', label="15 эпох")
# ax.plot(np.arange(15), e15r2, color='tab:orange')
# ax.plot(np.arange(15), e15r5, color='tab:orange')
# ax.plot(np.arange(15), e15r10, color='tab:orange')

# ax.hlines(43.572, 0, 14, color='tab:green', label="baseline")
# ax.hlines(55.256, 0, 14, color='tab:green')
# ax.hlines(69.188, 0, 14, color='tab:green')
# ax.hlines(78.308, 0, 14, color='tab:green')

# ax.plot(np.arange(5), mr1, color='tab:blue', label='ROCO 5 эпох')
# ax.plot(np.arange(5), mr2, color='tab:blue')
# ax.plot(np.arange(5), mr5, color='tab:blue')
# ax.plot(np.arange(5), mr10, color='tab:blue')
ax.plot(np.arange(14), m14r1, color='tab:orange', label="ROCO 14 эпох")
# ax.plot(np.arange(15), m15r1, color='tab:orange', label="ROCO 15 эпох")

ax.hlines(4.121, 0, 13, color='tab:green', label="baseline")
# ax.hlines(6.201, 0, 4, color='tab:green')
# ax.hlines(11.081, 0, 4, color='tab:green')
# ax.hlines(15.900, 0, 4, color='tab:green')

ax.set_xlabel("Эпоха")
ax.set_ylabel("Recall@1")
fig.legend()
fig.tight_layout()
ax.grid(True)

plt.show()