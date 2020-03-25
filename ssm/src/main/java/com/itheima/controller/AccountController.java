package com.itheima.controller;

import com.itheima.pojo.Account;
import com.itheima.service.AccountService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

/**
 * 账户web
 * @author JuJueZhe
 */
@Controller
@RequestMapping("/account")
public class AccountController {

 @Autowired
 private AccountService accountService;

 /**
  * 查询方法
  * @param model
  * @return
  */
 @RequestMapping("/findAll")
 public String findAll(Model model){
  System.out.println("表现层查询所有成功...");
  List<Account> accounts =  accountService.findAll();
  model.addAttribute("accounts",accounts);
  return "list";
 }

 /**
  * 保存方法
  * @return
  */
 @RequestMapping("/save")
 public void saveAccount(Account account, HttpServletRequest request, HttpServletResponse response) throws IOException {
  accountService.saveAccount(account);
  response.sendRedirect(request.getContextPath()+"/account/findAll");
 }
}
