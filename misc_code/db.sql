
CREATE DATABASE `school` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;

CREATE TABLE `orders` (
  `Order_id` varchar(4) NOT NULL,
  `Name` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `number` varchar(10) DEFAULT NULL,
  `prod_date` datetime NOT NULL,
  `pickedup` tinyint(1) NOT NULL DEFAULT '0',
  `door_nr` int NOT NULL,
  PRIMARY KEY (`Order_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
