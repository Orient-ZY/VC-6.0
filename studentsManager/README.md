## 首先对VC++6.0进行配置用以连接数据库操作

1、打开 `VC++6.0` -> 工具栏 `Tools` -> 选项 -> Directories(目录)标签页。在右方 `Show directories for：` （目录）下拉列表中选择 `Include files` ，然后在中间列表框中添加本地安装 `mysql` 的 `include` 目录路径。

2、在上面步骤中的 `Show directories for：` 下拉列表中选择 `Library files`，然后添加本地安装的 `MYSQL` 的 `Lib` 目录

3、打开 `VC++6.0` -> 工具栏 `Project` -> `Settings` 设置->　`Link` 链接 -> `Object/library modules` 对象/库模块。在最前方添加 `libmysql.lib `(有个空格)。

4、把 `MySQL` 安装目录下 `lib` 文件夹里的 `libmySQL.lib` 和 `libmySQL.dll` 拷贝到所建的工程目录下。

5、同时把 `libmySQL.lib` 拷贝到 `C:\WINDOWS\system32` 下。


## 安装数据库注意事项


![](https://github.com/Orient-ZY/OpenGL-Learning/raw/master/img/install.png)

上图安装的时候务必选择 `MySQL Servers` 中的 *x86* 版本，不然用VC++6.0会出现莫名其妙的BUG。

同时也需要要把 `MySQL Connectors` 中的 *x86* 版本勾上，否则将无法在安装路径里找到 `include` 文件夹。