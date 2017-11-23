import React, { Component } from 'react';
import { AppRegistry, StyleSheet, Text, View, Navigator } from 'react-native';
import Main from './App/Components/Main';
const styles = StyleSheet.create({
  container: {
    flex: 1
  }
//  navigatorStyles: {
//
//  }
});

export default class Rondeh extends Component {

  _renderScene(route, navigator) {
    var globalNavigatorProps = {navigator}

switch(route.ident) {
  case "MainPage":
  return (
    <Main
      {...globalNavigatorProps} />
  )
  //case "ActivitiesPage"

}

  }
  render() {
    return (
      <Navigator
        initialRoute={{ident: "MainPage"}}
        ref="appNavigator"
        style={styles.navigatorStyles}
        renderScene={this._renderScene} />
    )
  }
};

AppRegistry.registerComponent('Rondeh', () => Rondeh);
