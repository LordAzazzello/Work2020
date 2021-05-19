import sqlalchemy
from sqlalchemy.orm import sessionmaker
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import*

Base = declarative_base()


class Book(Base):
    __tablename__ = 'Книги'

    author = Column(Integer, ForeignKey('Авторы.id'), name='id_автора')
    title = Column(String, primary_key =True, name='Название')
    num_pages = Column(Integer, name ='Количество_страниц')
    publishing_house = Column(String, name='Издательство')
    year_publishing = Column(Integer, name='Год_издания')

    def __repr__(self):
        return "<Author(author_id={}, title='{}', sheets_count={}," \
               " publisher='{}', year={})>" \
            .format(self.author, self.title, self.num_pages,
                    self.publishing_house, self.year_publishing)
    

class Author(Base):
    __tablename__ = 'Авторы'

    id = Column(Integer, primary_key=True)
    name = Column(String, name ='Имя')
    country = Column(String, name ='Страна')
    years_life = Column(String, name ='Годы_жизни')

    def __repr__(self):
        return "<Author(id={}, name='{}', country='{}', years='{}')>" \
            .format(self.id, self.name, self.country, self.years_life)

def print_range(session):
    print('Вывод фамилий всех авторов, родившихся в диапазоне между 1800 и 1980 годами:\n')
    for author in session.query(Author):
        birthday = int(author.years_life.split('-')[0])
        if 1800 < birthday < 1980:
            print(author.name)
    print()


def print_russians(session):
    print('Вывод всех книг, написанных авторами из России:\n')
    authors = session.query(Author).filter(Author.country == 'Россия')
    for author in authors:
        books = session.query(Book).filter(Book.author == author.id)
        for book in books:
            print(book.title)
    print()


def print_pages(session):
    print('Вывод всех книг с количеством страниц более 100:\n')
    books = session.query(Book).filter(Book.num_pages > 100)
    for book in books:
        print(book.title)
    print()


def print_authors(session):
    print('Вывод всех авторов с числом книг более 1:\n')
    for author in session.query(Author):
        books = list(session.query(Book).filter(Book.author == author.id))
        if len(books) > 1:
            print(author.name)
    print()
