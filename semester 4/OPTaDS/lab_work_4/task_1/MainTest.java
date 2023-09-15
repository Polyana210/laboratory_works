package org.example;

import org.junit.Assert;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MainTest {

    @Test
    void Test1() {
        Assert.assertEquals(true,  Main.Check_balance("()<>[]{}"));
    }
    @Test
    void Test2() {
        Assert.assertEquals(true,  Main.Check_balance("(swsw[xxssx<xs{xs}xxs>s])"));
    }
    @Test
    void Test3() {
        Assert.assertEquals(false,  Main.Check_balance("()<>]{}"));
    }
    @Test
    void Test4() {
        Assert.assertEquals(false,  Main.Check_balance("(swsw[xxssx<xs>xs}xxs>s])"));
    }
}