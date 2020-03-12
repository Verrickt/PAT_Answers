弱鸡的[PAT](https://www.patest.cn/)甲级答案

克隆后使用VS2019打开工程。
因为VS把所有文件认为是同一个工程，不允许多个`main`入口点，若需使用请如下操作:

1. Solution explorer->Source files->Add existing items->选择你需要的文件，F5编译运行即可。

2. 调试完成后，Solution explorer->Source files->选中你不需要的文件右键->Exclude from project，即可移除

按照`(12)*`的顺序使用即可

<del>配合[博客](https://verrickt.github.io)食用更佳<del>

