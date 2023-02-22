import org.junit.Assert;
import org.junit.Test;

/*
 * Набор тестов. Как правило, для одного метода или класса
 * создаётся отдельный набор тестов, помещаемый в отдельный
 * класс. Имя этого класса может быть произвольным, но
 * желательно, чтобы оно отображало, какой метод или класс
 * будет тестироваться
 */
public class ExpressionTestCase {
    /*
     * каждый метод, начинающийся с аннотации @Test
     * представляет собой один тест, в котором, как
     * правило, представлен один набор тестовых данных
     */
    @Test
    public void test1() {
        Assert.assertEquals(
            0.7142857142857143, // ожидаемый результат
            Task1.expression(1, 2, 3), // вызов тестируемого методы
            0.0000000001 // для вещественных чисел погрешность сравнения
        );
    }

    @Test
    public void test2() {
        Assert.assertEquals(
            -0.16666666666666666,
            Task1.expression(0, 1, 1),
            0.0000000001
        );
    }

    @Test
    public void test3() {
        Assert.assertEquals(
            3.5555555555555554,
            Task1.expression(2, 2, 2),
            0.0000000001
        );
    }

    @Test
    public void test4() {
        Assert.assertEquals(
            48.092592592592595,
            Task1.expression(7, 7, 7),
            0.0000000001
        );
    }
}