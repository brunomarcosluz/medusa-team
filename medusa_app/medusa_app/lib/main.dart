import 'package:flutter/material.dart';

void main() {
  runApp(MedusaApp());
}

class MedusaApp extends StatefulWidget {
  const MedusaApp({super.key});

  @override
  State<MedusaApp> createState() => _MedusaAppSate();
}

class _MedusaAppSate extends State<MedusaApp> {

  bool isDarkMode = false;
  void toggleTheme() {
    setState(() {
      isDarkMode = !isDarkMode;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        theme: isDarkMode ? ThemeData.dark() : ThemeData.light(),
      home: Scaffold(
        appBar: AppBar(
          toolbarHeight: 70,
          centerTitle: true,
          title: const Text('Medusa - Gas Detection System'),
          elevation: 0,
          actions: [
            IconButton(
              icon: const Icon(Icons.brightness_4,),
              onPressed: () {
                toggleTheme();
              },
            ),
          ],
        ),
        body: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Container(
              child: Icon(Icons.access_alarms),
            ),
            
          ],
        ),
      ),
    );
  }
}

