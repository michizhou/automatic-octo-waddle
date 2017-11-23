import React, {Component} from 'react';
import {View, Text, StyleSheet, TextInput, Image, TouchableHighlight} from 'react-native';

class SearchBar extends Component {
  constructor(props) {
    super(props);
  this.state = {
    text:""
   };
}
handleEditText(e) {
  this.setState({text: e})
}
handleSendText() {
  this.props.onSendText(this.state.text)
}
render() {
  return(
        <View style={styles.searchBar}>
          <TextInput style={styles.inputBar}
            onChangeText={this.handleEditText.bind(this)}
            placeholder={"Enter a location (e.g LA, California or 19127)"}
            editable={true}
            value={this.state.text}
          />
          <TouchableHighlight underlayColor="transparent" onPress={this.handleSendText.bind(this)}>
            <View>
              <Image style={styles.image} source={require('./Images/sendTeal.png')}/>
              </View>
          </TouchableHighlight>
        </View>
  );
}
}
const styles = StyleSheet.create({
  searchBar: {
    height: 60,
    flexDirection: 'row',
    backgroundColor: '#B6B6B6',
    alignItems: 'center',
    justifyContent: 'center',
    paddingRight: 10,
    opacity: 35,
    borderBottomWidth: 1,
    borderLeftWidth: 1,
    borderRightWidth: 1
  },
  inputBar: {
    paddingLeft: 10,
    justifyContent: 'center',
    margin: 10,
    flex: 1,
    alignItems: 'center',
    backgroundColor: '#B6B6B6',
    fontSize: 14
  },
  image: {
    resizeMode: 'contain',
    height: 40,
    width: 40
  }
});





export default SearchBar
