package org.example;

import org.junit.Assert;

import static org.junit.Assert.*;

public class MainTest {

    @org.junit.Test
    public void Test1() {
        Main a = new Main();
        String string = "ed15deed5wd5ewd555ed8";
        Assert.assertEquals("eddeed5wd5ewded8", a.Task("ed15deed5wd5ewd555ed8"));

    }
    @org.junit.Test
    public void Test2() {
        Main a = new Main();
        String string = "gffrsesrt7go";
        Assert.assertEquals("gffrsesrt7go", a.Task("gffrsesrt7go"));
    }
    @org.junit.Test
    public void Test3() {
        Main a = new Main();
        String string = "gffrsesrtgo";
        Assert.assertEquals("gffrsesrtgo", a.Task("gffrsesrtgo"));
    }
    @org.junit.Test
    public void Test4() {
        Main a = new Main();
        String string = "55484189";
        Assert.assertEquals("", a.Task("55484189"));
    }
    @org.junit.Test
    public void Test5() {
        Main a = new Main();
        String string = "7";
        Assert.assertEquals("7", a.Task("7"));
    }
}