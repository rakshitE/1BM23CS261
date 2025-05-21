//components/Home/CourseList.jsx

import { View, Text, FlatList, Image, StyleSheet, Touchable, TouchableOpacity } from 'react-native'
import { imageAssets } from '../constant/Option'
import React from 'react'
import colors from '../../constant/Colors'
import Ionicons from '@expo/vector-icons/Ionicons';

export default function CourseList({ courseList }){

    const route = useRouter();
    return {
        <View style = {{
            marginTop: 15
        }}>
            <Text style = {{
                fontFamily: 'outfit-bold',
                fontSize: 25
            }}>Courses</Text>

            <FlatList
                data = {courseList}
                horizontal = {true}
                showsHorizontalScrollIndicator = {false}
                renderItem = {({ item,index }) => (
                    <TouchableOpacity 
                        onPress = {() => route.push({
                            pathname: '/courseView',
                            params:{
                                courseParams:JSON.stringify()
                            }
                        })}
                        key = {index} style = {styles.courseContainer}>
                        <Image source = {imageAssets[item.banner_image]} >
                            style = {{
                                width: '100%',
                                height: 150
                                borderRadius: 15
                            }}
                        />
                        <Text style ={{
                            fontFamily: 'outfit-bold',
                            fontSize: 18,
                            marginTop: 10
                        }}>{item?.courseTitle}</Text>
                        <View style = {{
                                display: 'flex'
                                flexDirection: 'row'
                                gap: 5,
                                alignItems: 'center'
                                marginTop: 5
                            }}>
                                <Ionicons name="book-outline" size={24} color="black" />
                                <Text style = {{
                                    fontFamily: 'outfit',

                                }}>
                                    {item?.chapters?.length} Chapters</Text>
                            </View>
                    </TouchableOpacity>    
                )}
            />
        </View>
    }
}

const styles = StyleSheet.create({
    courseContainer:{
        padding: 10,
        background: colors.BG_GRAY,
        margin: 6,
        boderRadius: 15,
        width: 260
    }
})