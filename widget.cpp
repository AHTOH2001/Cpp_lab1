#include "widget.h"

/* Функция для получения рандомного числа
 * в диапазоне от минимального до максимального
 * */
static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

void Widget::on_pushButton_clicked()
{
    MoveItem *item = new MoveItem();        // Создаём графический элемента
    item->setPos(randomBetween(30, 470),    // Устанавливаем случайную позицию элемента
                 randomBetween(30,470));
    scene->addItem(item);   // Добавляем элемент на графическую сцену
}
