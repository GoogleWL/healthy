<%@ page contentType="text/html;charset=UTF-8" language="java" isELIgnored="false" %>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <h3>查询所有账户信息成功...</h3>
    <c:forEach items="${accounts}" var="account">
       ${account.id}
       ${account.name}
       ${account.money}
    </c:forEach>

</body>
</html>
