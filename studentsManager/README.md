## ���ȶ�VC++6.0�������������������ݿ����

1���� `VC++6.0` -> ������ `Tools` -> ѡ�� -> Directories(Ŀ¼)��ǩҳ�����ҷ� `Show directories for��` ��Ŀ¼�������б���ѡ�� `Include files` ��Ȼ�����м��б������ӱ��ذ�װ `mysql` �� `include` Ŀ¼·����

2�������沽���е� `Show directories for��` �����б���ѡ�� `Library files`��Ȼ����ӱ��ذ�װ�� `MYSQL` �� `Lib` Ŀ¼

3���� `VC++6.0` -> ������ `Project` -> `Settings` ����->��`Link` ���� -> `Object/library modules` ����/��ģ�顣����ǰ����� `libmysql.lib `(�и��ո�)��

4���� `MySQL` ��װĿ¼�� `lib` �ļ������ `libmySQL.lib` �� `libmySQL.dll` �����������Ĺ���Ŀ¼�¡�

5��ͬʱ�� `libmySQL.lib` ������ `C:\WINDOWS\system32` �¡�


## ��װ���ݿ�ע������


![](https://github.com/Orient-ZY/OpenGL-Learning/raw/master/img/install.png)

��ͼ��װ��ʱ�����ѡ�� `MySQL Servers` �е� *x86* �汾����Ȼ��VC++6.0�����Ī�������BUG��

ͬʱҲ��ҪҪ�� `MySQL Connectors` �е� *x86* �汾���ϣ������޷��ڰ�װ·�����ҵ� `include` �ļ��С�