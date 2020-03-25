package com.itheima.test;

import com.itheima.service.AccountService;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * @author JuJueZhe
 */
public class testSpring {

 @Test
 public void testSpring01(){

  ApplicationContext applicationContext = new ClassPathXmlApplicationContext("classpath:applicationContext.xml");
  AccountService accountService = applicationContext.getBean("accountService", AccountService.class);
  accountService.findAll();

 }
}
