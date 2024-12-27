#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Address.h"
#include "Bag.h"
#include "Client.h"
#include "Coordinates.h"
#include "Courier.h"
#include "Date.h"
#include "Discount.h"
#include "Dish.h"
#include "Map.h"
#include "Menu.h"
#include "Order.h"
#include "Organisation.h"
#include "Person.h"
#include "Restaurant.h"
#include "Review.h"
#include "Schedule.h"
#include "Transport.h"


TEST(delivery_test, delivery_test1) {
  setlocale(0, "");
  Address client_address("Минск", "Якуба Коласа", 28, 1209);
  EXPECT_EQ(client_address._city, string("Минск"));
  EXPECT_EQ(client_address._street, string("Якуба Коласа"));
  EXPECT_EQ(client_address._home, 28);
  EXPECT_EQ(client_address._flat, 1209);

  vector <Order> client_orders;
  vector <bool> Yandex_Food_days = {1,1,1,1,1,1,1};
  vector <bool> Yandex_Food_hours = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  Schedule Yandex_Food_schedule(Yandex_Food_days, Yandex_Food_hours);
  EXPECT_EQ(Yandex_Food_schedule._days, Yandex_Food_days);
  EXPECT_EQ(Yandex_Food_schedule._hours, Yandex_Food_hours);

  vector <Restaurant> Yandex_Food_restaurants;
  Address KFC_address("Минск", "Сурганова", 57, 0);
  vector <bool> KFC_days = {1,1,1,1,1,1,1}, KFC_hours = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  Schedule KFC_schedule(KFC_days, KFC_hours);
  vector <Dish> KFC_dishes;
  Dish KFC_dish1("Картофель фри", "Фастфуд", 3.90);
  EXPECT_EQ(KFC_dish1._name, string("Картофель фри"));
  EXPECT_EQ(KFC_dish1._category, string("Фастфуд"));
  EXPECT_EQ(KFC_dish1._price, 3.90);

  KFC_dishes.push_back(KFC_dish1);
  Date start1(21,12,2024), end1(24,12,2024);
  EXPECT_EQ(start1._day, 21);
  EXPECT_EQ(start1._month, 12);
  EXPECT_EQ(start1._year, 2024);

  Discount KFC_discount1(KFC_dish1, 10, start1, end1);
  EXPECT_EQ(KFC_discount1._dish, KFC_dish1);
  EXPECT_EQ(KFC_discount1._procent, 10);
  EXPECT_EQ(KFC_discount1._start_date, start1);
  EXPECT_EQ(KFC_discount1._end_date, end1);

  vector <Discount> KFC_discounts;
  KFC_discounts.push_back(KFC_discount1);
  Menu KFC_menu(KFC_dishes, KFC_discounts);
  EXPECT_EQ(KFC_menu._dishes, KFC_dishes);
  EXPECT_EQ(KFC_menu._discounts, KFC_discounts);
  KFC_menu.calculate_price_with_discount(Date(23, 12, 2024));

  Restaurant KFC("KFC", KFC_address, KFC_schedule, KFC_menu);
  EXPECT_EQ(KFC._name, "KFC");
  EXPECT_EQ(KFC._address, KFC_address);
  EXPECT_EQ(KFC._schedule, KFC_schedule);
  EXPECT_EQ(KFC._menu, KFC_menu);

  Yandex_Food_restaurants.push_back(KFC);
  Organisation Yandex_Food("Яндекс Еда", Yandex_Food_schedule, Yandex_Food_restaurants, 0.6);
  EXPECT_EQ(Yandex_Food._name, "Яндекс Еда");
  EXPECT_EQ(Yandex_Food._schedule, Yandex_Food_schedule);
  EXPECT_EQ(Yandex_Food._restaurants, Yandex_Food_restaurants);
  EXPECT_EQ(Yandex_Food._delivery_coefficient, 0.6);

  vector <Dish> client_order_dishes;
  client_order_dishes.push_back(KFC_dish1);
  Order client_order1(Yandex_Food, KFC, client_order_dishes);
  EXPECT_EQ(client_order1._organisation, Yandex_Food);
  EXPECT_EQ(client_order1._restaurant, KFC);
  EXPECT_EQ(client_order1._dishes, client_order_dishes);

  client_orders.push_back(client_order1);
  vector <Dish> client_fav_dishes = {KFC_dish1};
  Client client('m', "Филиппов", "Руслан", "Михайлович", 19, 200, 100, client_address, client_orders, client_fav_dishes);
  EXPECT_EQ(client._sex, 'm');
  EXPECT_EQ(client._surname, string("Филиппов"));
  EXPECT_EQ(client._name, string("Руслан"));
  EXPECT_EQ(client._patronymic, string("Михайлович"));
  EXPECT_EQ(client._age, 19);
  EXPECT_EQ(client._salary, 200);
  EXPECT_EQ(client._balance, 100);
  EXPECT_EQ(client._address, client_address);
  EXPECT_EQ(client._orders, client_orders);
  EXPECT_EQ(client._favorite_dishes, client_fav_dishes);

  Transport courier_car("автомобиль", 120, "Volkswagen");
  EXPECT_EQ(courier_car._type, string("автомобиль"));
  EXPECT_EQ(courier_car._speed, 120);
  EXPECT_EQ(courier_car._mark, string("Volkswagen"));

  vector <bool> courier_days = {1,1,0,1,1,0,0}, courier_hours = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  Schedule courier_schedule(courier_days, courier_hours);
  Bag bag(5);
  EXPECT_EQ(bag._capacity, 5);
  bag.add_dish(KFC_dish1);
  Coordinates KFC_coords(1,1), client_coords(2,2);
  EXPECT_EQ(KFC_coords._latitude_degrees, 1);
  EXPECT_EQ(KFC_coords._longitude_degrees, 1);
  vector <Coordinates> rests_coords = {KFC_coords};
  Map map(rests_coords, client_coords);
  EXPECT_EQ(map._restaurant_coords, rests_coords);
  EXPECT_EQ(map._client_coords, client_coords);

  Courier courier('m', "Иванов", "Михаил", "Николаевич", 25, 2000, 1500, Yandex_Food, courier_car, courier_schedule, bag, map);
  EXPECT_EQ(courier._sex, 'm');
  EXPECT_EQ(courier._surname, string("Иванов"));
  EXPECT_EQ(courier._name, string("Михаил"));
  EXPECT_EQ(courier._patronymic, string("Николаевич"));
  EXPECT_EQ(courier._age, 25);
  EXPECT_EQ(courier._salary, 2000);
  EXPECT_EQ(courier._balance, 1500);
  EXPECT_EQ(courier._organisation, Yandex_Food);
  EXPECT_EQ(courier._transport, courier_car);
  EXPECT_EQ(courier._schedule, courier_schedule);
  EXPECT_EQ(courier._bag, bag);
  EXPECT_EQ(courier._map, map);
  Dish KFC_dish2("Пати баскет", "Фастфуд", 7.90);
  KFC.add_dish(KFC_dish2);
  EXPECT_EQ(KFC._menu._dishes[1], KFC_dish2);
  Dish KFC_dish3("Баскет дуэт", "Фастфуд", 21.90);
  KFC.add_dish(KFC_dish3); 
  for (int i = 0; i < client_order1._dishes.size(); i++)
      courier._bag.remove_dish(client_order1._dishes[i]);
  EXPECT_EQ(courier._bag._content.size(), 0);
  client.cancel_order(client_order1);
  client_order1.add_dish(KFC_dish2);
  courier._bag.add_dish(KFC_dish2);
  client_order1.add_dish(KFC_dish3);
  courier._bag.add_dish(KFC_dish3);
  client._orders.push_back(client_order1);

  vector <Dish> BK_dishes = {KFC_dish1};
  vector <Discount> BK_discounts = {};
  Menu BK_menu(BK_dishes, BK_discounts);
  Address BK_address("Минск", "Сурганова", 50, 0);
  Schedule BK_schedule = KFC_schedule;
  Restaurant Burger_King("Burger King", BK_address, BK_schedule, BK_menu);
  Yandex_Food_restaurants.push_back(Burger_King);   
  Coordinates BK_cords(1,2);
  courier._map._restaurant_coords.push_back(BK_cords);
  Dish BK_dish1("Гамбургер", "Фастфуд", 3);
  Burger_King.add_dish(BK_dish1);
  BK_dishes.push_back(BK_dish1);
  client.make_order(BK_dishes, Yandex_Food, Burger_King);
  EXPECT_EQ(client._orders[1]._cost, 6.9);
  EXPECT_EQ(client.calculate_final_cost(courier), 36.7);
  client.payment(courier);
  EXPECT_EQ(client._balance, 63.3);
  for (int i = 0; i < client._orders.size(); i++) 
      courier.took_order(client._orders[i]);
  courier.delivered_orders(client_orders);
  client.give_tips(courier, 10);
  EXPECT_EQ(courier._balance, 1510);
  EXPECT_EQ(client._balance, 53.3);

  EXPECT_EQ(KFC_schedule.object_is_working(2, 21), 1);
  EXPECT_EQ(KFC_schedule.object_is_working(2, 4), 0);

  EXPECT_EQ(courier._transport.calculate_travel_time(courier._map.calculate_distance(KFC_coords, client_coords)), 1.31);
  EXPECT_EQ(courier._transport.calculate_fuel_consumption(courier._map.calculate_distance(KFC_coords, client_coords)), 15.72);

  EXPECT_EQ(courier._map.find_the_nearest_restaurant(client_coords), 1);

  client.remove_favorite_dish(KFC_dish1);
  EXPECT_EQ(client._favorite_dishes.size(), 0);
  Dish BK_dish2("Наггетсы", "Фастфуд", 4);
  client.add_favorite_dish(BK_dish1);
  client.add_favorite_dish(BK_dish2);
  EXPECT_EQ(client._favorite_dishes.size(), 2);
  client.make_order_from_favorite_dishes(Yandex_Food, Burger_King);
  
  string text = "Все на высшем уровне. Заказ пришел быстро, курьер очень вежливый";
  client.leave_review(Yandex_Food, text, 10, Date(22, 12, 2024));
  EXPECT_EQ(Yandex_Food._reviews.size(), 1);
  Review review1 = Yandex_Food._reviews[0];
  EXPECT_EQ(review1._text, text);
  EXPECT_EQ(review1._rating, 10);
  EXPECT_EQ(review1._date, Date(22, 12, 2024));

  courier.salary_change(10);
  EXPECT_EQ(courier._salary, 2200);

  courier.replenishment_of_balance_by_salary();
  EXPECT_EQ(courier._balance, 3710);

  client.replenishment_of_balance(100);
  EXPECT_EQ(client._balance, 153.3);
  
  Review review2("Ужасная организация! Неудобный интерфейс, слишком долгая доставка(еда остыла), неприятный курьер!", 1, Date(23, 12, 2024));
  Yandex_Food._reviews.push_back(review2);
  Review review3("Заказ пришел быстро, однако курьер вел себя неподобающе", 8, Date(23, 12, 2024));
  Yandex_Food._reviews.push_back(review3);  
  double Yandex_Food_rating = Yandex_Food.calculate_average_rating();
  EXPECT_EQ(Yandex_Food_rating, 6.33);

  vector <Restaurant> EDU_restaurants;
  Address Sosedi_address("Минск", "Сурганова", 50, 0);
  vector <bool> Sosedi_days = {1,1,1,1,1,1,1}, Sosedi_hours = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  Schedule Sosedi_schedule(Sosedi_days, Sosedi_hours);
  vector <Dish> Sosedi_dishes;
  Dish Sosedi_dish1("Хлеб черный", "Хлебобулочное  изделие", 1.29);
  Sosedi_dishes.push_back(Sosedi_dish1);
  vector <Discount> Sosedi_discounts = {};
  Menu Sosedi_menu(Sosedi_dishes, Sosedi_discounts);
  Restaurant Sosedi("Соседи", Sosedi_address, Sosedi_schedule, Sosedi_menu);
  EDU_restaurants.push_back(Sosedi);
  Organisation EDU("ЕДУ!", Yandex_Food_schedule, EDU_restaurants, 0.4);

  Review review4("Неудобный интерфейс, но свою работу делают", 8, Date(19, 12, 2024));
  EDU._reviews.push_back(review4);

  vector <Restaurant> E_delivery_restaurants;
  Address Evroopt_address("Минск", "Якуба Коласа", 36, 0);
  vector <bool> Evroopt_days = {1,1,1,1,1,1,1}, Evroopt_hours = {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  Schedule Evroopt_schedule(Evroopt_days, Evroopt_hours);
  vector <Dish> Evroopt_dishes;
  Dish Evroopt_dish1("Молоко", "Молочное изделие", 1.49);
  Evroopt_dishes.push_back(Sosedi_dish1);
  vector <Discount> Evroopt_discounts = {};
  Menu Evroopt_menu(Evroopt_dishes, Evroopt_discounts);
  Restaurant Evroopt("Евроопт", Evroopt_address, Evroopt_schedule, Evroopt_menu);
  E_delivery_restaurants.push_back(Evroopt);
  Organisation E_delivery("Е-доставка", Yandex_Food_schedule, E_delivery_restaurants, 0.5); 

  Review review5("Доставка очень долгая, курьер не порадовал", 3, Date(23, 12, 2024));
  E_delivery._reviews.push_back(review5);
  Review review6("Все на высшем уровне!", 10, Date(23, 12, 2024));
  E_delivery._reviews.push_back(review6);  

  vector <Organisation> orgs = {Yandex_Food, EDU, E_delivery};
  Organisation best_org = find_the_best_organisation(orgs);
}





int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  ::testing::InitGoogleMock(&argc, argv);
  
  return RUN_ALL_TESTS();
}   