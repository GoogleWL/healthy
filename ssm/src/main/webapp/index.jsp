<%--
  Created by IntelliJ IDEA.
  User: JuJueZhe
  Date: 2020/3/24
  Time: 21:38
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <h3>测试查询</h3>
    <a href="account/findAll">查询所有用户信息</a><br>

    <h3>测试保存</h3>
    <form action="account/save" method="post">
        姓名:<input type="text" name="name"><br>
        金额:<input type="text" name="money"><br>
        <input type="submit" value="保存"><br>
    </form>

</body>
</html>
