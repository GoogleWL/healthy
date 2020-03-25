package com.itheima.test;

import com.itheima.dao.AccountDao;
import com.itheima.pojo.Account;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

/**
 * @author JuJueZhe
 */
public class testMybatis {

 private InputStream inputStream = null;
 private SqlSession session = null;
 private AccountDao accountDao = null;

 //用于在测试方法之前执行
 @Before
 public void init() throws IOException {
  //1.读取配置文件
  inputStream = Resources.getResourceAsStream("SqlMapConfig.xml");
  //2.创建SqlSessionFactory工厂
  SqlSessionFactoryBuilder builder = new SqlSessionFactoryBuilder();
  SqlSessionFactory factory = builder.build(inputStream);
  //3.使用工厂生产创建SqlSession对象
  session = factory.openSession();
  //使用SqlSession对象创建dao接口的代理对象
  accountDao = session.getMapper(com.itheima.dao.AccountDao.class);

 }

 //用于在测试方法之后执行
 @After
 public void destory() throws IOException {
  //提交事务
  session.commit();
  //释放资源
  session.close();
  inputStream.close();

 }

 @Test
 public void testFindAll() {
  List<Account> accounts = accountDao.findAll();
  for (Account account : accounts) {
   System.out.println(account);
  }
 }

 @Test
 public void testSave(){
  Account account = new Account();
  account.setMoney(520);
  account.setName("王健林");
  accountDao.saveAccount(account);
 }
}
