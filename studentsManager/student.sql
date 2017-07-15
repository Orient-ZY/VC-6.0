-- MySQL dump 10.13  Distrib 5.7.18, for Win32 (AMD64)
--
-- Host: localhost    Database: student
-- ------------------------------------------------------
-- Server version	5.7.18-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `college`
--

DROP TABLE IF EXISTS `college`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `college` (
  `id` varchar(15) COLLATE utf8_unicode_ci NOT NULL,
  `name` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `age` varchar(3) COLLATE utf8_unicode_ci NOT NULL,
  `gender` char(1) COLLATE utf8_unicode_ci NOT NULL,
  `grade` varchar(5) COLLATE utf8_unicode_ci NOT NULL,
  `major` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `english` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `program` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `math` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `sum` varchar(7) COLLATE utf8_unicode_ci DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `college`
--

LOCK TABLES `college` WRITE;
/*!40000 ALTER TABLE `college` DISABLE KEYS */;
INSERT INTO `college` VALUES ('301','��1','19','��','��һ1','87.0','67.0','78.0','67.0','299.0'),('302','��2','20','Ů','���2','78.0','67.0','89.0','99.0','333.0'),('303','��3','21','��','����1','98.0','89.0','78.0','89.0','354.0');
/*!40000 ALTER TABLE `college` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `junior`
--

DROP TABLE IF EXISTS `junior`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `junior` (
  `id` varchar(15) COLLATE utf8_unicode_ci NOT NULL,
  `name` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `age` varchar(3) COLLATE utf8_unicode_ci NOT NULL,
  `gender` char(1) COLLATE utf8_unicode_ci NOT NULL,
  `grade` varchar(5) COLLATE utf8_unicode_ci NOT NULL,
  `chinese` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `math` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `english` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `sum` varchar(7) COLLATE utf8_unicode_ci DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `junior`
--

LOCK TABLES `junior` WRITE;
/*!40000 ALTER TABLE `junior` DISABLE KEYS */;
INSERT INTO `junior` VALUES ('101','С1','6','��','һ1��','89.0','78.0','98.0','265.0'),('102','С2','5','Ů','һ1��','98.0','87.0','79.0','264.0'),('103','С2','7','��','��1��','67.0','78.0','98.0','243.0'),('104','С4','8','Ů','��2��','78.0','67.0','89.0','234.0');
/*!40000 ALTER TABLE `junior` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `secondary`
--

DROP TABLE IF EXISTS `secondary`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `secondary` (
  `id` varchar(15) COLLATE utf8_unicode_ci NOT NULL,
  `name` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `age` varchar(3) COLLATE utf8_unicode_ci NOT NULL,
  `gender` char(1) COLLATE utf8_unicode_ci NOT NULL,
  `grade` varchar(5) COLLATE utf8_unicode_ci NOT NULL,
  `chinese` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `math` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `english` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `geography` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `history` varchar(5) COLLATE utf8_unicode_ci DEFAULT '0',
  `sum` varchar(7) COLLATE utf8_unicode_ci DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `secondary`
--

LOCK TABLES `secondary` WRITE;
/*!40000 ALTER TABLE `secondary` DISABLE KEYS */;
INSERT INTO `secondary` VALUES ('203','��3','15','Ů','��2','67.0','54.0','78.0','68.0','97.0','364.0'),('202','��2','16','��','һ1','56.0','67.0','78.0','89.0','87.0','377.0'),('201','��1','15','��','��1','67.0','56.0','56.0','45.0','45.0','269.0');
/*!40000 ALTER TABLE `secondary` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-07-15 15:01:16
