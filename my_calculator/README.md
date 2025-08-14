This is user application for FPGA Prototyping 101.

---

0. Get sudo access
1. Execute ./set_qsize.sh. This script installs qdma-pf driver and sets qsize, interrupt ring size.
2. Execute ./initialize_queue.sh. This script adds h2c & c2h queue and starts them.
3. Execute ./my_calculator \<arg1> \<arg2>. Note that two arguments are unsigned int type.
4. Type `dmesg | grep -i qdma`. Then you can see the results.

2025.08.14
sangmyeon.yoon@mangoboost.io
