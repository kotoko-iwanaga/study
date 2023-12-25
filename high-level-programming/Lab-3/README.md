20. Написать программу, определяющую корректность описания методов класса

- Методы, связанные с классом, могут быть

  - внутри создаваемого класса
  - вне класса
    - в это случае я проверяю, определён ли класс до метода,
      нахождение прототипа метода не проверяется

- у методов могут быть параметры, произвожу проверку на некорректные параметры

- поддерживаются типы для методов

  - void
  - int
  - char
  - float
  - double
  - bool

- конструкции

  - class
  - struct (являются тоже классом в стандарте С++ 03)
  - union (являются тоже классом в стандарте С++ 03)

- после нахождения первой ошибки поведение не определено